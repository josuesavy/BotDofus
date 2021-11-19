#ifndef HOUSEINFORMATIONS_H
#define HOUSEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HouseInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HouseInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HouseInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HouseInformations(FuncTree tree);
  HouseInformations();
  bool operator==(const HouseInformations &compared);

  uint houseId;
  uint modelId;

private:
  void _houseIdFunc(Reader *input);
  void _modelIdFunc(Reader *input);
};

#endif // HOUSEINFORMATIONS_H