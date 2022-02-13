#include "ExchangeManager.h"

ExchangeManager::ExchangeManager(QMap<SocketIO *, BotData> *connectionsData):
    AbstractManager(ManagerType::EXCHANGE, connectionsData)
{

}

void ExchangeManager::reset(SocketIO *sender)
{
    m_botData[sender].exchangeData.sourceId = INVALID;
    m_botData[sender].exchangeData.isLackingKamas = false;
    m_botData[sender].exchangeData.objects.clear();
    m_botData[sender].exchangeData.step = 0;
    m_botData[sender].exchangeData.currentKamas = 0;
    m_botData[sender].exchangeData.isActive = false;
    m_botData[sender].exchangeData.isExchangingWithMaster = false;
}

void ExchangeManager::setState(SocketIO *sender, bool state)
{
    m_botData[sender].exchangeData.isActive = state;

    if(state)
        m_botData[sender].exchangeData.isLackingKamas = false;
}

bool ExchangeManager::isActive(SocketIO *sender) const
{
    return m_botData[sender].exchangeData.isActive;
}

void ExchangeManager::addRequestedObject(SocketIO *sender, const RequestTradeObject &item)
{
    int size = m_botData[sender].exchangeData.requestList.size();
    bool alreadyExist = false;

    for(int i = 0; i < size; i++)
    {
        if(m_botData[sender].exchangeData.requestList[i].GID == item.GID)
        {
            m_botData[sender].exchangeData.requestList[i] = item;
            alreadyExist = true;
            break;
        }
    }

    if(!alreadyExist)
        m_botData[sender].exchangeData.requestList<<item;
}

void ExchangeManager::removeRequestedObject(SocketIO *sender, uint objectGID)
{
    int size = m_botData[sender].exchangeData.requestList.size();

    for(int i = 0; i < size; i++)
    {
        if(m_botData[sender].exchangeData.requestList[i].GID == objectGID)
        {
            m_botData[sender].exchangeData.requestList.removeAt(i);
            break;
        }
    }
}

void ExchangeManager::updateExchange(SocketIO *sender)
{
    if(!m_botData[sender].exchangeData.isExchangingWithMaster)
    {
        int objectsCount = m_botData[sender].exchangeData.objects.size();
        int requestsCount = m_botData[sender].exchangeData.requestList.size();
        int kamas = 0;

        for(int i = 0; i < objectsCount; i++)
        {
            for(int j = 0; j < requestsCount; j++)
            {
                if(m_botData[sender].exchangeData.objects[i].GID == m_botData[sender].exchangeData.requestList[j].GID)
                {
                    if(m_botData[sender].exchangeData.objects[i].quantity <= m_botData[sender].exchangeData.requestList[j].quantity)
                    {
                        if(m_botData[sender].generalData.botState != EXCHANGING_STATE && m_botData[sender].exchangeData.requestList[j].quantity != -1)
                            m_botData[sender].exchangeData.requestList[j].quantity -= m_botData[sender].exchangeData.objects[i].quantity;

                        else if(m_botData[sender].generalData.botState == EXCHANGING_STATE)
                            kamas += m_botData[sender].exchangeData.objects[i].quantity * m_botData[sender].exchangeData.requestList[j].price;
                    }

                    else
                    {
                        if(m_botData[sender].generalData.botState != EXCHANGING_STATE)
                            m_botData[sender].exchangeData.requestList[j].quantity = 0;

                        else
                            kamas += m_botData[sender].exchangeData.requestList[j].price * m_botData[sender].exchangeData.requestList[j].quantity;
                    }

                    if(m_botData[sender].exchangeData.requestList[j].quantity == 0)
                    {
                        m_botData[sender].exchangeData.requestList.removeAt(j);
                        j--;
                        requestsCount--;
                    }
                }
            }
        }


        if(kamas > m_botData[sender].playerData.kamas)
        {
            if(m_botData[sender].exchangeData.isLackingKamas == false)
            {
                m_botData[sender].exchangeData.isLackingKamas = true;
                error(sender)<<"Vous n'avez plus assez d'argent pour les échanges";
                setState(sender, false);
                emit requestUpdate(sender);
            }

            kamas = m_botData[sender].playerData.kamas;

            if(kamas != m_botData[sender].exchangeData.currentKamas)
            {
                m_botData[sender].exchangeData.currentKamas = kamas;
                ExchangeObjectMoveKamaMessage answer;
                answer.quantity = kamas;
                sender->send(answer);
            }
        }

        else if(kamas != m_botData[sender].exchangeData.currentKamas)
        {
            m_botData[sender].exchangeData.currentKamas = kamas;
            ExchangeObjectMoveKamaMessage answer;
            answer.quantity = kamas;
            sender->send(answer);
        }
    }
}
