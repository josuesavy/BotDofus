#include "ElementsAdapter.h"

ElementsAdapter::ElementsAdapter():
    m_reader(NULL),
    m_isInit(false),
    m_element(NULL)
{

}

ElementsAdapter::ElementsAdapter(const QString &path)
{
    init(path);
}

ElementsAdapter::~ElementsAdapter()
{
    delete m_element;
    delete m_reader;
}

void ElementsAdapter::init(const QString &path)
{
    QTime t;
    t.start();

    m_isInit = true;
    m_path = path;

    QFile file(path);
    QByteArray ba = file.readAll();
    m_reader = new Reader(ba);

    int header = m_reader->readByte();
    if (header != 69)
    {
        m_reader->setPosition(0);
        ba = qUncompress(ba);
        m_reader = new Reader(ba);

        header = m_reader->readByte();
        if (header != 69)
        {
            qDebug() << "ERROR - ElementAdapter - Wrong header file.";
            return;
        }
    }
    m_reader->setPosition(0);
    m_element = new Elements(m_reader);

    qDebug()<<"[ElementsAdapter] Initialized ! ("<<t.elapsed()<<"ms)";
}

bool ElementsAdapter::isInit()
{
    return m_isInit;
}

Elements *ElementsAdapter::getElement()
{
    return m_element;
}
