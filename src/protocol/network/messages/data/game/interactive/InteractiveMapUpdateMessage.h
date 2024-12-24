#ifndef INTERACTIVEMAPUPDATEMESSAGE_H
#define INTERACTIVEMAPUPDATEMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/interactive/InteractiveElement.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class InteractiveMapUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveMapUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveMapUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveMapUpdateMessage(FuncTree tree);
  InteractiveMapUpdateMessage();

  QList<QSharedPointer<InteractiveElement>> interactiveElements;

private:
  void _interactiveElementstreeFunc(Reader *input);
  void _interactiveElementsFunc(Reader *input);

  FuncTree _interactiveElementstree;
};

#endif // INTERACTIVEMAPUPDATEMESSAGE_H