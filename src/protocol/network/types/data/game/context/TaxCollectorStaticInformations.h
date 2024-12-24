#ifndef TAXCOLLECTORSTATICINFORMATIONS_H
#define TAXCOLLECTORSTATICINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/utils/io/type/FuncTree.h"

class TaxCollectorStaticInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorStaticInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorStaticInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorStaticInformations(FuncTree tree);
  TaxCollectorStaticInformations();
  bool operator==(const TaxCollectorStaticInformations &compared);

  uint firstNameId;
  uint lastNameId;
  QSharedPointer<AllianceInformation> allianceIdentity;
  double callerId;
  QString uid;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _allianceIdentitytreeFunc(Reader *input);
  void _callerIdFunc(Reader *input);
  void _uidFunc(Reader *input);

  FuncTree _allianceIdentitytree;
};

#endif // TAXCOLLECTORSTATICINFORMATIONS_H