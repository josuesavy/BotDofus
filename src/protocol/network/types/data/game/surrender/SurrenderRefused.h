#ifndef SURRENDERREFUSED_H
#define SURRENDERREFUSED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderResponse.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderRefused : public SurrenderResponse
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderRefused(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderRefused(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderRefused(FuncTree tree);
  SurrenderRefused();
  bool operator==(const SurrenderRefused &compared);
};

#endif // SURRENDERREFUSED_H