#ifndef TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H
#define TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/BasicGuildInformations.h"
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
  uint wisdom;
  uint taxCollectorsCount;
  int taxCollectorAttack;
  double kamas;
  double experience;
  uint pods;
  double itemsValue;

private:
  void _maxPodsFunc(Reader *input);
  void _prospectingFunc(Reader *input);
  void _wisdomFunc(Reader *input);
  void _taxCollectorsCountFunc(Reader *input);
  void _taxCollectorAttackFunc(Reader *input);
  void _kamasFunc(Reader *input);
  void _experienceFunc(Reader *input);
  void _podsFunc(Reader *input);
  void _itemsValueFunc(Reader *input);
};

#endif // TAXCOLLECTORDIALOGQUESTIONEXTENDEDMESSAGE_H