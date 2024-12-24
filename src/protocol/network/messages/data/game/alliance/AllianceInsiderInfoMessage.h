#ifndef ALLIANCEINSIDERINFOMESSAGE_H
#define ALLIANCEINSIDERINFOMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/alliance/AllianceMemberInfo.h"
#include "src/protocol/network/types/data/game/collector/tax/TaxCollectorInformations.h"
#include "src/protocol/network/types/data/game/prism/PrismGeolocalizedInformation.h"
#include "src/protocol/network/types/data/game/social/AllianceFactSheetInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceInsiderInfoMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceInsiderInfoMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceInsiderInfoMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceInsiderInfoMessage(FuncTree tree);
  AllianceInsiderInfoMessage();

  QSharedPointer<AllianceFactSheetInformation> allianceInfos;
  QList<QSharedPointer<AllianceMemberInfo>> members;
  QList<QSharedPointer<PrismGeolocalizedInformation>> prisms;
  QList<QSharedPointer<TaxCollectorInformations>> taxCollectors;

private:
  void _allianceInfostreeFunc(Reader *input);
  void _memberstreeFunc(Reader *input);
  void _membersFunc(Reader *input);
  void _prismstreeFunc(Reader *input);
  void _prismsFunc(Reader *input);
  void _taxCollectorstreeFunc(Reader *input);
  void _taxCollectorsFunc(Reader *input);

  FuncTree _allianceInfostree;
  FuncTree _memberstree;
  FuncTree _prismstree;
  FuncTree _taxCollectorstree;
};

#endif // ALLIANCEINSIDERINFOMESSAGE_H