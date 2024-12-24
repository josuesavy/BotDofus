#ifndef SURRENDERREFUSEDBEFOREVOTE_H
#define SURRENDERREFUSEDBEFOREVOTE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderRefused.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderRefusedBeforeVote : public SurrenderRefused
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderRefusedBeforeVote(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderRefusedBeforeVote(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderRefusedBeforeVote(FuncTree tree);
  SurrenderRefusedBeforeVote();
  bool operator==(const SurrenderRefusedBeforeVote &compared);
};

#endif // SURRENDERREFUSEDBEFOREVOTE_H