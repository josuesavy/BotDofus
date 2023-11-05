#ifndef KOHALLIANCEROLEMEMBERS_H
#define KOHALLIANCEROLEMEMBERS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class KohAllianceRoleMembers : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KohAllianceRoleMembers(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KohAllianceRoleMembers(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KohAllianceRoleMembers(FuncTree tree);
  KohAllianceRoleMembers();
  bool operator==(const KohAllianceRoleMembers &compared);

  double memberCount;
  int roleAvAId;

private:
  void _memberCountFunc(Reader *input);
  void _roleAvAIdFunc(Reader *input);
};

#endif // KOHALLIANCEROLEMEMBERS_H