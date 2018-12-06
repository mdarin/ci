<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>form_{$imitator}</class>
 <widget class="QWidget" name="form_{$imitator}">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>322</width>
    <height>359</height>
   </rect>
  </property>
  <property name="minimumSize">
   <size>
    <width>311</width>
    <height>359</height>
   </size>
  </property>
  <property name="maximumSize">
   <size>
    <width>10000</width>
    <height>10000</height>
   </size>
  </property>
  <property name="windowTitle">
   <string>{$imitator}</string>
  </property>
  <widget class="QTabWidget" name="tabWidget">
   <property name="geometry">
    <rect>
     <x>10</x>
     <y>0</y>
     <width>311</width>
     <height>351</height>
    </rect>
   </property>
   <property name="currentIndex">
    <number>0</number>
   </property>
   <widget class="QWidget" name="tab">
   <attribute name="title">
     <string>FrontPanel</string>
    </attribute>
    <widget class="QGroupBox" name="groupBox_7">
     <property name="geometry">
      <rect>
       <x>90</x>
       <y>50</y>
       <width>111</width>
       <height>191</height>
      </rect>
     </property>
     <property name="title">
      <string/>
     </property>
     <widget class="CDiode" name="cDiode">
      <property name="geometry">
       <rect>
        <x>50</x>
        <y>40</y>
        <width>21</width>
        <height>21</height>
       </rect>
      </property>
      <property name="minimumSize">
       <size>
        <width>20</width>
        <height>20</height>
       </size>
      </property>
      <property name="ID">
       <string>HL1</string>
      </property>
      <property name="Domain">
       <string>IND</string>
      </property>
     </widget>
     <widget class="CTumbler" name="cTumbler">
      <property name="geometry">
       <rect>
        <x>40</x>
        <y>100</y>
        <width>40</width>
        <height>40</height>
       </rect>
      </property>
      <property name="minimumSize">
       <size>
        <width>40</width>
        <height>40</height>
       </size>
      </property>
      <property name="ID">
       <string>SA1</string>
      </property>
      <property name="Domain">
       <string>CTR</string>
      </property>
      <property name="orientation">
       <enum>Qt::Vertical</enum>
      </property>
     </widget>
    </widget>
   </widget>
   <widget class="QWidget" name="tab_2">
    <attribute name="title">
     <string>Rear</string>
    </attribute>
   </widget>
  </widget>
 </widget>
 <customwidgets>
  <customwidget>
   <class>CDiode</class>
   <extends>QWidget</extends>
   <header>cdiode.h</header>
  </customwidget>
  <customwidget>
   <class>CTumbler</class>
   <extends>QWidget</extends>
   <header>ctumbler.h</header>
  </customwidget>
 </customwidgets>
 <resources/>
 <connections/>
</ui>
