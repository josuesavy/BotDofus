#ifndef KOTHWINNER_H
#define KOTHWINNER_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

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