#ifndef TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/BasicAllianceInformations.h"
#include "src/protocol/types/data/game/context/roleplay/BasicNamedAllianceInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/context/roleplay/npc/TaxCollectorDialogQuestionBasicMessage.h"

class TaxCollectorDialogQuestionExtendedMessage : public TaxCollectorDialogQuestionBasicMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorDialogQuestionExtendedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorDialogQuestionExtendedMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorDialogQuestionExtendedMessage(FuncTree tree);
  TaxCollectorDialogQuestionExtendedMessage();

  uint maxPods;
  uint prospecting;
  QSharedPointer<BasicNamedAllianceInformations> alliance;
  uint taxCollectorsCount;
  int taxCollectorAttack;
  uint pods;
  double itemsValue;

private:
  void _maxPodsFunc(Reader *input);
  void _prospectingFunc(Reader *input);
  void _alliancetreeFunc(Reader *input);
  void _taxCollectorsCountFunc(Reader *input);
  void _taxCollectorAttackFunc(Reader *input);
  void _podsFunc(Reader *input);
  void _itemsValueFunc(Reader *input);

  FuncTree _alliancetree;
};

#endif // TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H