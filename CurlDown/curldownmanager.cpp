#include "curldownmanager.h"
#include "curl/curl.h"

#include "mycurldown.h"

CurlDownManager *CurlDownManager::m_manager = nullptr;
std::mutex CurlDownManager::m_mutex;
std::map<UnitWidget *, CurlDownElement *> CurlDownManager::m_map;
std::mutex CurlDownManager::m_map_mutex;


CurlDownManager::CurlDownManager()
{
    curl_global_init(CURL_GLOBAL_ALL);
}

CurlDownManager::~CurlDownManager()
{
    curl_global_cleanup();
}

CurlDownManager *CurlDownManager::GetCurDownManager()
{
    std::unique_lock<std::mutex> lock(m_mutex);

    if(m_manager == nullptr)
        m_manager = new CurlDownManager();

    return m_manager;
}

void CurlDownManager::FreeCurDownManager()
{
    std::unique_lock<std::mutex> lock(m_mutex);

    if(m_manager){
        delete m_manager;
        m_manager = nullptr;
    }
}

void CurlDownManager::AddCurlDown(UnitWidget *u)
{
    std::unique_lock<std::mutex> lock(m_map_mutex);
    if(m_map.count(u)){
        delete m_map[u];
        m_map[u] = nullptr;
    }

    DownInformation info = u->GetInformation();
    //qDebug() << info.FileName;

    m_map[u] = new CurlDownElement();
    m_map[u]->SetInformation(info);
    QObject::connect(m_map[u], SIGNAL(finished()), m_map[u], SLOT(deleteLater()));  //线程结束之后自动销毁
    QObject::connect(m_map[u], SIGNAL(HasFinished()), u, SLOT(OK()));
    QObject::connect(m_map[u], SIGNAL(OnProgress(double,double)), u, SLOT(OnProgress(double, double)));
    QObject::connect(u, SIGNAL(Pause()), m_map[u], SLOT(Pause()));


    m_map[u]->start();
}

void CurlDownManager::EraseCurlDown(UnitWidget *u)
{
    std::unique_lock<std::mutex> lock(m_map_mutex);
    if(m_map.count(u)){
        qDebug() << "curldownmanager1";
        m_map[u]->Stop();       //关闭存在问题
        qDebug() << "curldownmanager2";

        m_map[u]->quit();
        qDebug() << "curldownmanager3";

        m_map[u]->wait();
        qDebug() << "curldownmanager4";

        m_map[u]->exit();
        qDebug() << "curldownmanager5";

        //delete m_map[u];
        m_map.erase(u);
        qDebug() << "curldownmanager6";

    }
}

void CurlDownManager::ClearManager()
{
    std::unique_lock<std::mutex> lock(m_map_mutex);
    for(auto it = m_map.begin(); it != m_map.end(); ++it){
        delete it->second;
    }

    m_map.clear();
}





