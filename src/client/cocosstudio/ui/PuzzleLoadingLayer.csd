<GameFile>
  <PropertyGroup Name="PuzzleLoadingLayer" Type="Layer" ID="c2321c8f-173d-4f77-85b2-777ec509c6bb" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="112" Speed="1.0000">
        <Timeline ActionTag="1660001046" Property="Position">
          <PointFrame FrameIndex="0" X="375.0000" Y="756.1289">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="112" X="375.0000" Y="756.1289">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1660001046" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="112" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1660001046" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="112" X="360.0000" Y="360.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Layer" Tag="75" ctype="GameLayerObjectData">
        <Size X="750.0000" Y="1334.0000" />
        <Children>
          <AbstractNodeData Name="puzzle_loading_bg_1" ActionTag="-1042853349" Tag="76" IconVisible="False" ctype="SpriteObjectData">
            <Size X="750.0000" Y="1334.0000" />
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="Normal" Path="ui/menuRes/puzzle_loading_bg.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="BitmapFontLabel_1" ActionTag="928685203" Tag="77" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="164.0000" RightMargin="164.0000" TopMargin="764.5306" BottomMargin="489.4694" LabelText="正在努力加载中..." ctype="TextBMFontObjectData">
            <Size X="422.0000" Y="80.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="375.0000" Y="529.4694" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.3969" />
            <PreSize X="0.5627" Y="0.0600" />
            <LabelBMFontFile_CNB Type="Normal" Path="fonts/typeface-export.fnt" Plist="" />
          </AbstractNodeData>
          <AbstractNodeData Name="loading_2" ActionTag="1660001046" Tag="78" RotationSkewX="360.0000" RotationSkewY="360.0000" IconVisible="False" PositionPercentXEnabled="True" LeftMargin="280.0000" RightMargin="280.0000" TopMargin="482.8711" BottomMargin="661.1289" ctype="SpriteObjectData">
            <Size X="190.0000" Y="190.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="375.0000" Y="756.1289" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5668" />
            <PreSize X="0.2533" Y="0.1424" />
            <FileData Type="Normal" Path="ui/menuRes/loading.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>