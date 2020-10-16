#ifndef INTERACTIVEELEMENTUPDATEDMESSAGE_H
#define INTERACTIVEELEMENTUPDATEDMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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