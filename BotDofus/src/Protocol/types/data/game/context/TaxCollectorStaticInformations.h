#ifndef TAXCOLLECTORSTATICINFORMATIONS_H
#define TAXCOLLECTORSTATICINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"

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
  QSharedPointer<GuildInformations> guildIdentity;
  double callerId;

private:
  void _firstNameIdFunc(Reader *input);
  void _lastNameIdFunc(Reader *input);
  void _guildIdentitytreeFunc(Reader *input);
  void _callerIdFunc(Reader *input);

  FuncTree _guildIdentitytree;
};

#endif // TAXCOLLECTORSTATICINFORMATIONS_H