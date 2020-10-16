#ifndef INTERACTIVEMAPUPDATEMESSAGE_H
#define INTERACTIVEMAPUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/interactive/InteractiveElement.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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