# UnrealGameProject (TowerPrototype Draft)
언리얼5 기반으로, 전달받은 기획 이미지를 바탕으로 **초안 프로젝트 골격(C++ 기반)** 을 구성했습니다.

## 포함된 초안 기능
- 좌측 필드 + 우측 상호작용 UI 구조를 위한 기본 HUD 위젯 클래스 (`UMainHUDWidget`)
- 상단 자원(HP / 골드 / 수정체) 상태 데이터 (`ATPPlayerState`)
- 라운드/페이즈(정비/전투), 남은 시간, 몬스터 수, 보스까지 라운드 계산 (`ATPGameState`)
- 기본 게임 모드/플레이어 컨트롤러에서 HUD 생성 (`ATPGameModeBase`, `ATPPlayerController`)

## 프로젝트 열기
1. Unreal Engine 5.3 이상에서 `TowerPrototype.uproject` 열기
2. C++ 컴파일 허용 (최초 열기 시 프로젝트 파일 생성)

## 에디터에서 해야 할 연결 작업 (필수)
초안 코드는 “로직 틀” 중심이므로, 아래 블루프린트 연결이 필요합니다.

1. `UMainHUDWidget` 기반 위젯 블루프린트 생성 (`WBP_MainHUD` 권장)
2. 위젯 안에서 텍스트/프로그레스바를 아래 이름으로 배치해 Bind
   - `HPText`, `GoldText`, `ShardText`
   - `TimerLabelText`, `TimeProgressBar`
   - `RemainingMonsterText`, `CurrentRoundText`, `BossRoundText`
3. `ATPPlayerController` 기반 BP 생성 후 `MainHUDWidgetClass`에 `WBP_MainHUD` 할당
4. `ATPGameModeBase` 기반 BP 생성 후 PlayerController/GameState/PlayerState 확인
5. 월드 세팅에서 해당 GameMode를 기본값으로 지정

## 현재 구현 범위
- **구현됨**: 자원 수치 증감 API, 라운드 타이머 순환, UI 표시 데이터 공급
- **미구현(다음 단계)**:
  - 실제 “몹 이동 루트” 스폰/이동 AI
  - 유닛 뽑기/강화 창 상세 로직
  - 도박 이벤트 시스템
  - DataTable(GlobalConst/RoundData/String_UI) 연동
  - 필드 배치/충돌/전투 계산

## 다음 추천 작업
1. DataTable 구조 먼저 확정 (`HP_min/max`, `Gold_min/max`, `phase1_time`, `phase2_time` 등)
2. `ATPGameState`를 DataTable 기반으로 초기화하도록 확장
3. 필드용 스폰 매니저 액터(`ABattleLaneManager`) 추가
4. 상호작용 버튼(유닛 뽑기/강화/도박) UMG 이벤트를 Subsystem으로 분리

