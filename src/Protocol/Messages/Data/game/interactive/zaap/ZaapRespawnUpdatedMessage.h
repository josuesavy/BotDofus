#ifndef ZAAPRESPAWNUPDATEDMESSAGE_H
#define ZAAPRESPAWNUPDATEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ZaapRespawnUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ZaapRespawnUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ZaapRespawnUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ZaapRespawnUpdatedMessage(FuncTree tree);
  ZaapRespawnUpdatedMessage();

  double mapId;

private:
  void _mapIdFunc(Reader *input);
};

#endif // ZAAPRESPAWNUPDATEDMESSAGE_H