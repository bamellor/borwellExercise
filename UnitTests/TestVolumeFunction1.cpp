#include "stdafx.h"
#include "PaintEstimator.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace UnitTests
{
	[TestClass]
	public ref class TestVolumeFunction1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes

		#pragma endregion 

		[TestMethod]
        // test that the wall area is calculated correctly - output matches expected value
		void TestWallArea()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateWallArea(), 13.2, 0.01, "Should be equal");
            // use the tolerance parameter as float arithmetic will suffer small variations
		};
        [TestMethod]
        // test that the floor area is calculated correctly - output matches expected value
		void TestFloorArea()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateFloorArea(), 3.84, 0.01, "Should be equal");
		};
        [TestMethod]
        // test that the roomn volume is calculated correctly - output matches expected value
		void TestVolume()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual((double)workerClass.CalculateVolume(), 5.76, 0.01, "Should be equal");
		};
        [TestMethod]
        // test that the paint volume is calculated correctly - output matches expected value
		void TestPaintReq()
		{
            float fWidth =  1.2f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            float fWallArea = workerClass.CalculateWallArea(); 
            Assert::AreEqual((double)workerClass.CalculatePaintReq(fWallArea), 10.56, 0.01, "Should be equal");
		};
        [TestMethod]
        // test that the zero length dimensions are rejected
		void TestZeroWidth()
		{
            float fWidth =  0.0f;
            float fLength = 3.2f;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual(workerClass.ValidateMeasurements(), false, "Should be false");
		};
        [TestMethod]
        // test that the very large dimensions are rejected
		void TestFltMaxLength()
		{
            float fWidth =  1.2f;
            float fLength = FLT_MAX;
            float fHeight = 1.5f;
            float fCoverage = 1.25f;
            CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);
            Assert::AreEqual(workerClass.ValidateMeasurements(), false, "Should be false");
		};
	};
}
