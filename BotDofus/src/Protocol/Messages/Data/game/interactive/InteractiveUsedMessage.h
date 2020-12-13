#ifndef INTERACTIVEUSEDMESSAGE_H
#define INTERACTIVEUSEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class InteractiveUsedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveUsedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveUsedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveUsedMessage(FuncTree tree);
  InteractiveUsedMessage();

  double entityId;
  uint elemId;
  uint skillId;
  uint duration;
  bool canMove;

private:
  void _entityIdFunc(Reader *input);
  void _elemIdFunc(Reader *input);
  void _skillIdFunc(Reader *input);
  void _durationFunc(Reader *input);
  void _canMoveFunc(Reader *input);
};

#endif // INTERACTIVEUSEDMESSAGE_H