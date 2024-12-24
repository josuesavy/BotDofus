#ifndef INTERACTIVEELEMENTUPDATEDMESSAGE_H
#define INTERACTIVEELEMENTUPDATEDMESSAGE_H

#include "src/protocol/network/types/data/game/interactive/InteractiveElement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class InteractiveElementUpdatedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveElementUpdatedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveElementUpdatedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveElementUpdatedMessage(FuncTree tree);
  InteractiveElementUpdatedMessage();

  QSharedPointer<InteractiveElement> interactiveElement;

private:
  void _interactiveElementtreeFunc(Reader *input);

  FuncTree _interactiveElementtree;
};

#endif // INTERACTIVEELEMENTUPDATEDMESSAGE_H