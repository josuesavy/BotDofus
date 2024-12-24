#ifndef ABSTRACTPLAYERSEARCHINFORMATION_H
#define ABSTRACTPLAYERSEARCHINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class AbstractPlayerSearchInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AbstractPlayerSearchInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AbstractPlayerSearchInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AbstractPlayerSearchInformation(FuncTree tree);
  AbstractPlayerSearchInformation();
  bool operator==(const AbstractPlayerSearchInformation &compared);
};

#endif // ABSTRACTPLAYERSEARCHINFORMATION_H