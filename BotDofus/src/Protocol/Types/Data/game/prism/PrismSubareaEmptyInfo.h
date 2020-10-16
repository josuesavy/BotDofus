#ifndef PRISMSUBAREAEMPTYINFO_H
#define PRISMSUBAREAEMPTYINFO_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PrismSubareaEmptyInfo : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismSubareaEmptyInfo(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismSubareaEmptyInfo(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismSubareaEmptyInfo(FuncTree tree);
  PrismSubareaEmptyInfo();
  bool operator==(const PrismSubareaEmptyInfo &compared);

  uint subAreaId;
  uint allianceId;

private:
  void _subAreaIdFunc(Reader *input);
  void _allianceIdFunc(Reader *input);
};

#endif // PRISMSUBAREAEMPTYINFO_H