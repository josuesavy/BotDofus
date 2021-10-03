#ifndef GAMEACTIONMARK_H
#define GAMEACTIONMARK_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/actions/fight/GameActionMarkedCell.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GameActionMark : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionMark(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionMark(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionMark(FuncTree tree);
  GameActionMark();
  bool operator==(const GameActionMark &compared);

  double markAuthorId;
  uint markTeamId;
  uint markSpellId;
  int markSpellLevel;
  int markId;
  int markType;
  int markimpactCell;
  QList<GameActionMarkedCell> cells;
  bool active;

private:
  void _markAuthorIdFunc(Reader *input);
  void _markTeamIdFunc(Reader *input);
  void _markSpellIdFunc(Reader *input);
  void _markSpellLevelFunc(Reader *input);
  void _markIdFunc(Reader *input);
  void _markTypeFunc(Reader *input);
  void _markimpactCellFunc(Reader *input);
  void _cellstreeFunc(Reader *input);
  void _cellsFunc(Reader *input);
  void _activeFunc(Reader *input);

  FuncTree _cellstree;
};

#endif // GAMEACTIONMARK_H