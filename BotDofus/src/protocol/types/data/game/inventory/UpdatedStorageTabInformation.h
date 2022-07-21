#ifndef UPDATEDSTORAGETABINFORMATION_H
#define UPDATEDSTORAGETABINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class UpdatedStorageTabInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_UpdatedStorageTabInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_UpdatedStorageTabInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_UpdatedStorageTabInformation(FuncTree tree);
  UpdatedStorageTabInformation();
  bool operator==(const UpdatedStorageTabInformation &compared);

  QString name;
  uint tabNumber;
  uint picto;
  QList<uint> dropTypeLimitation;

private:
  void _nameFunc(Reader *input);
  void _tabNumberFunc(Reader *input);
  void _pictoFunc(Reader *input);
  void _dropTypeLimitationtreeFunc(Reader *input);
  void _dropTypeLimitationFunc(Reader *input);

  FuncTree _dropTypeLimitationtree;
};

#endif // UPDATEDSTORAGETABINFORMATION_H