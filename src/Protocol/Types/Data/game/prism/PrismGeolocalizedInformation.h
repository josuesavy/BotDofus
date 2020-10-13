#ifndef PRISMGEOLOCALIZEDINFORMATION_H
#define PRISMGEOLOCALIZEDINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/prism/PrismInformation.h"
#include "src/Protocol/Types/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class PrismGeolocalizedInformation : public PrismSubareaEmptyInfo
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismGeolocalizedInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismGeolocalizedInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismGeolocalizedInformation(FuncTree tree);
  PrismGeolocalizedInformation();
  bool operator==(const PrismGeolocalizedInformation &compared);

  int worldX;
  int worldY;
  double mapId;
  QSharedPointer<PrismInformation> prism;

private:
  void _worldXFunc(Reader *input);
  void _worldYFunc(Reader *input);
  void _mapIdFunc(Reader *input);
  void _prismtreeFunc(Reader *input);

  FuncTree _prismtree;
};

#endif // PRISMGEOLOCALIZEDINFORMATION_H