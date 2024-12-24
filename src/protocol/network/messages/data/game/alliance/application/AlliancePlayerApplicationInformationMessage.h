#ifndef ALLIANCEPLAYERAPPLICATIONINFORMATIONMESSAGE_H
#define ALLIANCEPLAYERAPPLICATIONINFORMATIONMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/protocol/network/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/alliance/application/AlliancePlayerApplicationAbstractMessage.h"

class AlliancePlayerApplicationInformationMessage : public AlliancePlayerApplicationAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePlayerApplicationInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePlayerApplicationInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePlayerApplicationInformationMessage(FuncTree tree);
  AlliancePlayerApplicationInformationMessage();

  QSharedPointer<AllianceInformation> allianceInformation;
  QSharedPointer<SocialApplicationInformation> apply;

private:
  void _allianceInformationtreeFunc(Reader *input);
  void _applytreeFunc(Reader *input);

  FuncTree _allianceInformationtree;
  FuncTree _applytree;
};

#endif // ALLIANCEPLAYERAPPLICATIONINFORMATIONMESSAGE_H