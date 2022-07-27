#ifndef GUILDLOGBOOKINFORMATIONMESSAGE_H
#define GUILDLOGBOOKINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/guild/logbook/GuildLogbookEntryBasicInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildLogbookInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLogbookInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLogbookInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLogbookInformationMessage(FuncTree tree);
  GuildLogbookInformationMessage();

  QList<QSharedPointer<GuildLogbookEntryBasicInformation>> globalActivities;
  QList<QSharedPointer<GuildLogbookEntryBasicInformation>> chestActivities;

private:
  void _globalActivitiestreeFunc(Reader *input);
  void _globalActivitiesFunc(Reader *input);
  void _chestActivitiestreeFunc(Reader *input);
  void _chestActivitiesFunc(Reader *input);

  FuncTree _globalActivitiestree;
  FuncTree _chestActivitiestree;
};

#endif // GUILDLOGBOOKINFORMATIONMESSAGE_H