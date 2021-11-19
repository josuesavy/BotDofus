#ifndef ZAAPRESPAWNSAVEREQUESTMESSAGE_H
#define ZAAPRESPAWNSAVEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class ZaapRespawnSaveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ZaapRespawnSaveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ZaapRespawnSaveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ZaapRespawnSaveRequestMessage(FuncTree tree);
  ZaapRespawnSaveRequestMessage();
};

#endif // ZAAPRESPAWNSAVEREQUESTMESSAGE_H