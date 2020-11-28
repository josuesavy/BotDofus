#include "GameInventorySpellsFrame.h"

GameInventorySpellsFrame::GameInventorySpellsFrame(QMap<SocketIO *, BotData> *connectionsData):
    AbstractFrame(connectionsData)
{

}

bool GameInventorySpellsFrame::processMessage(const MessageInfos &data, SocketIO *sender)
{
    bool messageFound = true;
    Reader reader(data.messageData);

    switch (data.messageType)
    {
    default :
        messageFound = false;
        break;

    case MessageEnum::SPELLLISTMESSAGE:
    {
        SpellListMessage message;
        message.deserialize(&reader);

        m_botData[sender].playerData.spells.clear();
        foreach(SpellItem spell, message.spells)
        {
            Spell spellData;
            spellData.spellID = spell.spellId;
            spellData.spellLevel = spell.spellLevel;
            m_botData[sender].playerData.spells[spell.spellId] = spellData;
        }
    }
        break;
    }

    return messageFound;
}
