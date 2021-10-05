#ifndef MOUNTXPRATIOMESSAGE_H
#define MOUNTXPRATIOMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class MountXpRatioMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountXpRatioMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountXpRatioMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountXpRatioMessage(FuncTree tree);
  MountXpRatioMessage();

  uint ratio;

private:
  void _ratioFunc(Reader *input);
};

#endif // MOUNTXPRATIOMESSAGE_H