#ifndef GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H
#define GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameContextRemoveMultipleElementsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameContextRemoveMultipleElementsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameContextRemoveMultipleElementsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameContextRemoveMultipleElementsMessage(FuncTree tree);
  GameContextRemoveMultipleElementsMessage();

  QList<double> elementsIds;

private:
  void _elementsIdstreeFunc(Reader *input);
  void _elementsIdsFunc(Reader *input);

  FuncTree _elementsIdstree;
};

#endif // GAMECONTEXTREMOVEMULTIPLEELEMENTSMESSAGE_H