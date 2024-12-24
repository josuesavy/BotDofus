#ifndef SELLERBUYERDESCRIPTOR_H
#define SELLERBUYERDESCRIPTOR_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class SellerBuyerDescriptor : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SellerBuyerDescriptor(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SellerBuyerDescriptor(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SellerBuyerDescriptor(FuncTree tree);
  SellerBuyerDescriptor();
  bool operator==(const SellerBuyerDescriptor &compared);

  QList<uint> quantities;
  QList<uint> types;
  double taxPercentage;
  double taxModificationPercentage;
  uint maxItemLevel;
  uint maxItemPerAccount;
  int npcContextualId;
  uint unsoldDelay;

private:
  void _quantitiestreeFunc(Reader *input);
  void _quantitiesFunc(Reader *input);
  void _typestreeFunc(Reader *input);
  void _typesFunc(Reader *input);
  void _taxPercentageFunc(Reader *input);
  void _taxModificationPercentageFunc(Reader *input);
  void _maxItemLevelFunc(Reader *input);
  void _maxItemPerAccountFunc(Reader *input);
  void _npcContextualIdFunc(Reader *input);
  void _unsoldDelayFunc(Reader *input);

  FuncTree _quantitiestree;
  FuncTree _typestree;
};

#endif // SELLERBUYERDESCRIPTOR_H