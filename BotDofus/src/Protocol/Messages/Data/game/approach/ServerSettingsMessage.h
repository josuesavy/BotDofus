#ifndef SERVERSETTINGSMESSAGE_H
#define SERVERSETTINGSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ServerSettingsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerSettingsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerSettingsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerSettingsMessage(FuncTree tree);
  ServerSettingsMessage();

  QString lang;
  uint community;
  int gameType;
  bool isMonoAccount;
  uint arenaLeaveBanTime;
  uint itemMaxLevel;
  bool hasFreeAutopilot;

private:
  void deserializeByteBoxes(Reader *input);
  void _langFunc(Reader *input);
  void _communityFunc(Reader *input);
  void _gameTypeFunc(Reader *input);
  void _arenaLeaveBanTimeFunc(Reader *input);
  void _itemMaxLevelFunc(Reader *input);
};

#endif // SERVERSETTINGSMESSAGE_H