#ifndef TAXCOLLECTORBASICINFORMATIONS_H
#define TAXCOLLECTORBASICINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TaxCollectorBasicInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorBasicInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorBasicInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorBasicInformations(FuncTree tree);
  TaxCollectorBasicInformations();
  bool operator==(const TaxCollectorBasicInformations &compared);

  uint firstNameId;
  uint lastNameId;
  int worldX;
  int worldY;
  double mapId;
  uint subAreaId;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _subAreaIdFunc(Reader *input);
};

#endif // TAXCOLLECTORBASICINFORMATIONS_H