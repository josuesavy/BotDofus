#ifndef DEBUGHIGHLIGHTCELLSMESSAGE_H
#define DEBUGHIGHLIGHTCELLSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class DebugHighlightCellsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_DebugHighlightCellsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_DebugHighlightCellsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_DebugHighlightCellsMessage(FuncTree tree);
  DebugHighlightCellsMessage();

  double color;
  QList<uint> cells;

private:
  void _colorFunc(Reader *input);
  void _cellstreeFunc(Reader *input);
  void _cellsFunc(Reader *input);

  FuncTree _cellstree;
};

#endif // DEBUGHIGHLIGHTCELLSMESSAGE_H