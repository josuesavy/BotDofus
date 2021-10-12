#ifndef ELEMENTSADAPTER_H
#define ELEMENTSADAPTER_H

#include <QDataStream>

#include "src/Public.h"
#include "src/engines/io/ele/Elements.h"
#include "src/engines/io/network/Reader.h"
#include "src/engines/io/utils/Singleton.h"

class ElementsAdapter
{
    friend class Singleton<ElementsAdapter>;

public:
    ElementsAdapter();
    ElementsAdapter(const QString &path);
    ~ElementsAdapter();

    void init(const QString &path);

    bool isInit();
    Elements *getElement();

private:
    Reader *m_reader;
    QString m_path;
    bool m_isInit;

    Elements *m_element;
};

class ElementsAdapterSingleton : public Singleton<ElementsAdapter>
{
};

#endif // ELEMENTSADAPTER_H
