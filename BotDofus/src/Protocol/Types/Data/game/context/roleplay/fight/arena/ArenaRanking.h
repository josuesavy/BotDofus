#ifndef ARENARANKING_H
#define ARENARANKING_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class ArenaRanking : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ArenaRanking(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ArenaRanking(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ArenaRanking(FuncTree tree);
  ArenaRanking();
  bool operator==(const ArenaRanking &compared);

  uint rank;
  uint bestRank;

private:
  void _rankFunc(Reader *input);
  void _bestRankFunc(Reader *input);
};

#endif // ARENARANKING_H