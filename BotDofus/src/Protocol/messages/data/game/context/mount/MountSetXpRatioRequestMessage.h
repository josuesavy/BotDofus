#ifndef MOUNTSETXPRATIOREQUESTMESSAGE_H
#define MOUNTSETXPRATIOREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountSetXpRatioRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountSetXpRatioRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountSetXpRatioRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountSetXpRatioRequestMessage(FuncTree tree);
  MountSetXpRatioRequestMessage();

  uint xpRatio;

private:
  void _xpRatioFunc(Reader *input);
};

#endif // MOUNTSETXPRATIOREQUESTMESSAGE_H