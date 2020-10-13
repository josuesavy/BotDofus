#ifndef TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H
#define TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Protocol/Types/Data/game/context/TaxCollectorStaticInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class TaxCollectorStaticExtendedInformations : public TaxCollectorStaticInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorStaticExtendedInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorStaticExtendedInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorStaticExtendedInformations(FuncTree tree);
  TaxCollectorStaticExtendedInformations();
  bool operator==(const TaxCollectorStaticExtendedInformations &compared);

  QSharedPointer<AllianceInformations> allianceIdentity;

private:
  void _allianceIdentitytreeFunc(Reader *input);

  FuncTree _allianceIdentitytree;
};

#endif // TAXCOLLECTORSTATICEXTENDEDINFORMATIONS_H