#ifndef HUMANOPTION_H
#define HUMANOPTION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HumanOption : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOption(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOption(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOption(FuncTree tree);
  HumanOption();
  bool operator==(const HumanOption &compared);
};

#endif // HUMANOPTION_H