#ifndef STATISTICDATASTRING_H
#define STATISTICDATASTRING_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/common/basic/StatisticData.h"
#include "src/utils/io/type/FuncTree.h"

class StatisticDataString : public StatisticData
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatisticDataString(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatisticDataString(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatisticDataString(FuncTree tree);
  StatisticDataString();
  bool operator==(const StatisticDataString &compared);

  QString value;

private:
  void _valueFunc(Reader *input);
};

#endif // STATISTICDATASTRING_H