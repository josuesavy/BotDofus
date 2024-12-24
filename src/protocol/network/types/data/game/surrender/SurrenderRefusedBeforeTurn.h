#ifndef SURRENDERREFUSEDBEFORETURN_H
#define SURRENDERREFUSEDBEFORETURN_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderRefused.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderRefusedBeforeTurn : public SurrenderRefused
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderRefusedBeforeTurn(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderRefusedBeforeTurn(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderRefusedBeforeTurn(FuncTree tree);
  SurrenderRefusedBeforeTurn();
  bool operator==(const SurrenderRefusedBeforeTurn &compared);

  int minTurnForSurrender;

private:
  void _minTurnForSurrenderFunc(Reader *input);
};

#endif // SURRENDERREFUSEDBEFORETURN_H