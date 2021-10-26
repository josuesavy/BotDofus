#include "LuaFunctions.h"

LuaFunctions::LuaFunctions()
{
    m_Init = false;
}

LuaFunctions::LuaFunctions(lua_State *L)
{
    m_L = L;
    m_Init = false;

    init();
}

void LuaFunctions::init()
{
    CharacterMethods::Register(m_L, m_sender);
    ChatMethods::Register(m_L);
    CraftMethods::Register(m_L);
    GlobalMethods::Register(m_L);
    InventoryMethods::Register(m_L);
    JobMethods::Register(m_L);
    MapMethods::Register(m_L);
    NpcMethods::Register(m_L);

    m_Init = true;
}

bool LuaFunctions::isInit()
{
    return m_Init;
}

void LuaFunctions::setSender(SocketIO *sender)
{
    m_sender = sender;
}

SocketIO *LuaFunctions::getSender()
{
    return m_sender;
}

void LuaFunctions::setLuaState(lua_State *L)
{
    m_L = L;
}

lua_State *LuaFunctions::getLuaState()
{
    return m_L;
}
