#ifndef GUILDLOGBOOKENTRYBASICINFORMATION_H
#define GUILDLOGBOOKENTRYBASICINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class GuildLogbookEntryBasicInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLogbookEntryBasicInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLogbookEntryBasicInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLogbookEntryBasicInformation(FuncTree tree);
  GuildLogbookEntryBasicInformation();
  bool operator==(const GuildLogbookEntryBasicInformation &compared);

  uint id;
  double date;

private:
  void _idFunc(Reader *input);
  void _dateFunc(Reader *input);
};

#endif // GUILDLOGBOOKENTRYBASICINFORMATION_H