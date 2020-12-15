#ifndef PADDOCKINFORMATIONS_H
#define PADDOCKINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class PaddockInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PaddockInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PaddockInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PaddockInformations(FuncTree tree);
  PaddockInformations();
  bool operator==(const PaddockInformations &compared);

  uint maxOutdoorMount;
  uint maxItems;

private:
  void _maxOutdoorMountFunc(Reader *input);
  void _maxItemsFunc(Reader *input);
};

#endif // PADDOCKINFORMATIONS_H