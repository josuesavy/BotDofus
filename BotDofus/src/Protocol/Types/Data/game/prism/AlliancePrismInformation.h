#ifndef ALLIANCEPRISMINFORMATION_H
#define ALLIANCEPRISMINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/AllianceInformations.h"
#include "src/Protocol/Types/Data/game/prism/PrismInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AlliancePrismInformation : public PrismInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePrismInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePrismInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePrismInformation(FuncTree tree);
  AlliancePrismInformation();
  bool operator==(const AlliancePrismInformation &compared);

  QSharedPointer<AllianceInformations> alliance;

private:
  void _alliancetreeFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // ALLIANCEPRISMINFORMATION_H