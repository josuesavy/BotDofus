#ifndef KOTHWINNER_H
#define KOTHWINNER_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class KothWinner : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KothWinner(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KothWinner(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KothWinner(FuncTree tree);
  KothWinner();
  bool operator==(const KothWinner &compared);
};

#endif // KOTHWINNER_H