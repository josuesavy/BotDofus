#ifndef MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H
#define MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class MapRunningFightDetailsRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MapRunningFightDetailsRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MapRunningFightDetailsRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MapRunningFightDetailsRequestMessage(FuncTree tree);
  MapRunningFightDetailsRequestMessage();

  uint fightId;

private:
  void _fightIdFunc(Reader *input);
};

#endif // MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE_H