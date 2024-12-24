#ifndef STORAGETABINFORMATION_H
#define STORAGETABINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class StorageTabInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StorageTabInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StorageTabInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StorageTabInformation(FuncTree tree);
  StorageTabInformation();
  bool operator==(const StorageTabInformation &compared);

  QString name;
  uint tabNumber;
  uint picto;
  uint openRight;
  uint dropRight;
  uint takeRight;
  QList<uint> dropTypeLimitation;

private:
  void _nameFunc(Reader *input);
  void _tabNumberFunc(Reader *input);
  void _pictoFunc(Reader *input);
  void _openRightFunc(Reader *input);
  void _dropRightFunc(Reader *input);
  void _takeRightFunc(Reader *input);
  void _dropTypeLimitationtreeFunc(Reader *input);
  void _dropTypeLimitationFunc(Reader *input);

  FuncTree _dropTypeLimitationtree;
};

#endif // STORAGETABINFORMATION_H