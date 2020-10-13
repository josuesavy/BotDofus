#ifndef GAMEACTIONMARKEDCELL_H
#define GAMEACTIONMARKEDCELL_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GameActionMarkedCell : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionMarkedCell(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionMarkedCell(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionMarkedCell(FuncTree tree);
  GameActionMarkedCell();
  bool operator==(const GameActionMarkedCell &compared);

  uint cellId;
  int zoneSize;
  int cellColor;
  int cellsType;

private:
  void _cellIdFunc(Reader *input);
  void _zoneSizeFunc(Reader *input);
  void _cellColorFunc(Reader *input);
  void _cellsTypeFunc(Reader *input);
};

#endif // GAMEACTIONMARKEDCELL_H