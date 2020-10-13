#ifndef PADDOCKMOVEITEMREQUESTMESSAGE_H
#define PADDOCKMOVEITEMREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PaddockMoveItemRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockMoveItemRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockMoveItemRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockMoveItemRequestMessage(FuncTree tree);
  PaddockMoveItemRequestMessage();

  uint oldCellId;
  uint newCellId;

private:
  void _oldCellIdFunc(Reader *input);
  void _newCellIdFunc(Reader *input);
};

#endif // PADDOCKMOVEITEMREQUESTMESSAGE_H