#ifndef DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H
#define DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class DebugClearHighlightCellsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebugClearHighlightCellsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebugClearHighlightCellsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebugClearHighlightCellsMessage(FuncTree tree);
  DebugClearHighlightCellsMessage();
};

#endif // DEBUGCLEARHIGHLIGHTCELLSMESSAGE_H