#ifndef CURLDOWNMANAGER_H
#define CURLDOWNMANAGER_H

#include <mutex>
#include <map>

#include "unitwidget.h"
#include "curldownelement.h"

class CurlDownManager
{
public:
    static CurlDownManager *GetCurDownManager();
    static void FreeCurDownManager();
    static void AddCurlDown(UnitWidget *);
    static void EraseCurlDown(UnitWidget *);
    static void ClearManager();

private:
    CurlDownManager();
    ~CurlDownManager();

    static CurlDownManager *m_manager;
    static std::mutex m_mutex;
    static std::map<UnitWidget*,CurlDownElement *> m_map;
    static std::mutex m_map_mutex;
};

#endif // CURLDOWNMANAGER_H
